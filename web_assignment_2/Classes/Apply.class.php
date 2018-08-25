<?php

require_once 'Mysql.class.php';

class Apply extends Mysql
{
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
  private $OptionalString = 'other-skills';
  private $StateList = [ 'VIC', 'NSW', 'QLD', 'NT', 'WA', 'SA', 'TAS', 'ACT' ];

  public function __construct()
  {
    parent::__construct();
  }

  private function validateData($key, $value)
  {
    switch ($key) {
      case 'job-reference-number':
        return strlen($value) === 6;
        break;
      case 'first-name':
        return strlen($value) < 25;
        break;
      case 'last-name':
        return strlen($value) < 25;
        break;
      case 'date-of-birth':
        return $value === date('d/m/Y', strtotime(str_replace('/', '-', $value)));
        break;
      case 'gender':
        return $value === 'Male' || $value === 'Female';
        break;
      case 'street-address':
        return strlen($value) < 40;
        break;
      case 'suburb-town':
        return strlen($value) < 40;
        break;
      case 'state':
        return in_array($value, $this->StateList);
        break;
      case 'postcode':
        return strlen($value) === 4 && filter_var($value, FILTER_VALIDATE_INT);
        break;
      case 'email-address':
        return filter_var($value, FILTER_VALIDATE_EMAIL);
        break;
      case 'phone-number':
        return filter_var(str_replace(' ', '', $value), FILTER_VALIDATE_INT);
        break;
      case 'skill-list':
        return count($value) !== 0;
        break;
      
      default:
        return false;
        break;
    }
  }

  private function validate()
  {
    $this->valid = true;
    foreach ($this->RequiredString as $value) {
      if (!isset($_POST[$value]) || empty($_POST[$value])) {
        $this->valid = false;
      } else {
        if (!$this->validateData($value, $_POST[$value])) {
          $this->valid = false;
        }
      }
    }

    if (isset($_POST['skill-list'])) {
      if (isset($_POST['skill-list']['other-skills'])) {
        if (isset($_POST[$this->OptionalString])) {
          if (empty($_POST[$this->OptionalSting])) {
            $this->valid = false;
          }
        }
      }
    }

    return $this->valid;
  }

  private function sanitize($data)
  {
    return htmlspecialchars(trim($data));
  }

  public function apply()
  {
    if ($this->validate()) {
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

      $status = 'created';
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
      print "Invalid data";
    }
  }

  public function __destruct()
  {
    parent::__destruct();
  }
}


?>