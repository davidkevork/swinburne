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

  public function tableExists()
  {
    $tableCreateSql = "CREATE TABLE `application` (
      `EOInumber` int(10) NOT NULL AUTO_INCREMENT PRIMARY KEY,
      `reference` varchar(6) NOT NULL,
      `firstname` varchar(25) NOT NULL,
      `lastname` varchar(25) NOT NULL,
      `dob` varchar(9) NOT NULL,
      `gender` varchar(10) NOT NULL,
      `address` varchar(40) NOT NULL,
      `suburb` varchar(40) NOT NULL,
      `state` varchar(3) NOT NULL,
      `postcode` int(4) NOT NULL,
      `email` varchar(256) NOT NULL,
      `phone` varchar(12) NOT NULL,
      `skills` varchar(256) NOT NULL,
      `otherskills` varchar(256) NOT NULL,
      `status` varchar(10) NOT NULL
    ) ENGINE=InnoDB DEFAULT CHARSET=latin1;";
    $tableExistsSql = "DESCRIBE `application`";
    $tableExists = $this->mysqli->query($tableExistsSql);
    if (!$tableExists)
    {
      $tableCreate = $this->mysqli->query($tableCreateSql);
      $tableCreate->close();
    }
    $tableExists->close();
  }

  private function validateData($key, $value)
  {
    switch ($key) {
      case 'job-reference-number':
        return strlen($value) === 6 ? 'job' : 'none';
        break;
      case 'first-name':
        return strlen($value) < 25 ? 'firstname' : 'none';
        break;
      case 'last-name':
        return strlen($value) < 25 ? 'lastname' : 'none';
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
        return count($value) !== 0 ? 'skill=;ist' : 'none';
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