<?php

require_once 'Mysql.class.php';

class Apply extends Mysql
{
  // list of required data which are of string format
  private $RequiredString = [
    'job-reference-number',
    'first-name',
    'last-name',
    'date-of-birth',
    'gender',
    'street-address', 
    'suburb-town',
    'state',
    'postcode',
    'email-address',
    'phone-number',
    'skill-list',
  ];
  // optional data of string format
  private $OptionalString = 'other-skills';
  // list of states in australia
  private $StateList = [ 'VIC', 'NSW', 'QLD', 'NT', 'WA', 'SA', 'TAS', 'ACT' ];

  public function __construct()
  {
    parent::__construct();
  }

  private function validatePostCode($post, $state)
  {
    switch ($state)
    {
      case 'VIC':
        if (strpos($post, '3', 0) === false && strpos($post, '8', 0) === false) {
          return false;
        }
        break;
      case 'NSW':
        if (strpos($post, '1', 0) === false && strpos($post, '2', 0) === false) {
          return false;
        }
        break;
      case 'QLD':
        if (strpos($post, '4', 0) === false && strpos($post, '9', 0) === false) {
          return false;
        }
        break;
      case 'NT':
        if (strpos($post, '0', 0) === false) {
          return false;
        }
        break;
      case 'WA':
        if (strpos($post, '6', 0) === false) {
          return false;
        }
        break;
      case 'SA':
        if (strpos($post, '5', 0) === false) {
          return false;
        }
        break;
      case 'TAS':
        if (strpos($post, '7', 0) === false) {
          return false;
        }
        break;
      case 'ACT':
        if (strpos($post, '0', 0) === false) {
          return false;
        }
        break;
      default:
        return false;
    };
    return true;
  }

  private function getAge($date) {
    return intval(date('Y', time())) - intval((new DateTime($date))->format('Y'));
  }

  private function validateAge($age)
  {
    if ($this->getAge($age) > 80 || $this->getAge($age) < 15) {
      return false;
    }
    return true;
  }

  // data validation function
  private function validateData($key, $value)
  {
    switch ($key) {
      case 'job-reference-number':
        return strlen($value) === 6 ? 'job' : 'none';
        break;
      case 'first-name':
        return strlen($value) < 25 || !preg_match("/^[a-zA-Z]+$/", $value) ? 'firstname' : 'none';
        break;
      case 'last-name':
        return strlen($value) < 25 || !preg_match("/^[a-zA-Z]+$/", $value) ? 'lastname' : 'none';
        break;
      case 'date-of-birth':
        return $value === date('d/m/Y', strtotime(str_replace('/', '-', $value))) ? 'date' : 'none';
        break;
      case 'gender':
        return ($value === 'Male' || $value === 'Female') ? 'gender' : 'none';
        break;
      case 'street-address':
        return strlen($value) < 40 ? 'street' : 'none';
        break;
      case 'suburb-town':
        return strlen($value) < 40 ? 'town' : 'none';
        break;
      case 'state':
        return in_array($value, $this->StateList) ? 'state' : 'none';
        break;
      case 'postcode':
        return strlen($value) === 4 && filter_var($value, FILTER_VALIDATE_INT) ? 'postcode' : 'none';
        break;
      case 'email-address':
        return filter_var($value, FILTER_VALIDATE_EMAIL) ? 'email-address' : 'none';
        break;
      case 'phone-number':
        return filter_var(str_replace(' ', '', $value), FILTER_VALIDATE_INT) ? 'phone' : 'none';
        break;
      case 'skill-list':
        return count($value) === false ? 'skill-list' : 'none';
        break;
      
      default:
        return 'none';
        break;
    }
  }

  // validated te given functions before adding to database
  private function validate()
  {
    $this->valid = true;
    $list = [];
    foreach ($this->RequiredString as $value) {
      if (!isset($_POST[$value]) || empty($_POST[$value])) {
        $this->valid = false;
        array_push($list, 'Empty value');
      } else {
        if (!$this->validateData($value, $_POST[$value])) {
          array_push($list, $this->validateData($value, $_POST[$value]) . ' invaild');
          $this->valid = false;
        }
      }
    }

    if ($this->validatePostCode($_POST['postcode'], $_POST['state']) === false) {
      array_push($list, 'Invalid postcode');
      $this->valid = false;
    }

    if ($this->validateAge($_POST['date-of-birth']) === false) {
      array_push($list, 'Age invalid');
      $this->valid = false;
    }

    if (isset($_POST['skill-list'])) {
      if (isset($_POST['skill-list']['other-skills'])) {
        if (isset($_POST[$this->OptionalString])) {
          if (empty($_POST[$this->OptionalSting])) {
            array_push($list, 'Skill list cant be empty');
            $this->valid = false;
          }
        }
      }
    }

    if (count($list) > 0) {
      print_r(($list));
    }

    return $this->valid;
  }

  // sanitized the input for xss
  private function sanitize($data)
  {
    return htmlspecialchars(trim($data));
  }

  // apply function
  public function apply()
  {
    // validates data and if all is valid then process
    $validate = $this->validate();
    if ($validate) {
      // get the data and sanitize all of them
      $this->Reference = $this->sanitize($_POST['job-reference-number']);
      $this->FirstName = $this->sanitize($_POST['first-name']);
      $this->LastName = $this->sanitize($_POST['last-name']);
      $this->DOB = $this->sanitize($_POST['date-of-birth']);
      $this->Gender = $this->sanitize($_POST['gender']);
      $this->StreetAddress = $this->sanitize($_POST['street-address']); 
      $this->Suburb = $this->sanitize($_POST['suburb-town']);
      $this->State = $this->sanitize($_POST['state']);
      $this->Postcode = $_POST['postcode'];
      $this->EmailAddress = $this->sanitize($_POST['email-address']);
      $this->PhoneNumber = $this->sanitize($_POST['phone-number']);
      $this->SkillList = json_encode($_POST['skill-list']);
      $this->OtherSkills = isset($_POST['other-skills']) ? $this->sanitize($_POST['other-skills']) : '';

      // insert into database
      $status = 'New';
      $applySql = 'INSERT INTO `application` (`reference`, `firstname`, `lastname`, `dob`, `gender`, `address`, `suburb`, `state`, `postcode`, `email`, `phone`, `skills`, `otherskills`, `status`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)';
      $apply = $this->mysqli->prepare($applySql);
      $apply->bind_param('ssssssssisssss',
        $this->Reference,
        $this->FirstName,
        $this->LastName,
        $this->DOB,
        $this->Gender,
        $this->StreetAddress,
        $this->Suburb,
        $this->State,
        $this->Postcode,
        $this->EmailAddress,
        $this->PhoneNumber,
        $this->SkillList,
        $this->OtherSkills,
        $status);
      $apply->execute();
      printf("New Record has id %d.", $this->mysqli->insert_id);
      $apply->close();
    } else {
      print 'INVALID DATA';
    }
  }

  public function __destruct()
  {
    parent::__destruct();
  }
}

?>
