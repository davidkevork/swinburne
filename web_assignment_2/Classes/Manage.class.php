<?php

require_once 'Mysql.class.php';

class Manage extends Mysql
{
  public function __construct()
  {
    parent::__construct();
  }

  // checks php session if user is logged in
  public static function isLoggedInSession()
  {
    return isset($_SESSION['loggedIn']) && !empty($_SESSION['loggedIn']);
  }

  // create session for manager and set to loggedIn
  public static function logInSession()
  {
    $_SESSION['loggedIn'] = 'loggedIn';
  }

  // registers a new managger
  public function register()
  {
    if (isset($_POST['register'])) {
      $username = isset($_POST['username']) ? htmlspecialchars(trim($_POST['username'])) : '';
      $password = isset($_POST['password']) ? htmlspecialchars(trim($_POST['password'])) : '';
      if (!empty($username) && !empty($password)) {
        $checkAccountSql = "SELECT `password` FROM `manager` WHERE `username` = ?";
        $checkAccount = $this->mysqli->prepare($checkAccountSql);
        $checkAccount->bind_param('s', $username);
        $checkAccount->execute();
        $checkAccount->store_result();
        $totalRows = $checkAccount->num_rows;
        if ($totalRows === 0) {
          $checkAccount->close();
          $password = password_hash($password, PASSWORD_DEFAULT);
          $registerSql = "INSERT INTO `manager` (`username`, `password`) VALUES (?, ?)";
          $register = $this->mysqli->prepare($registerSql);
          $register->bind_param('ss', $username, $password);
          $register->execute();
          if ($register) {
            $register->close();
            return 'Account registered';
          } else {
            $register->close();
            return 'Unable to create account';
          }
        } else {
          $checkAccount->close();
          return 'Account already exists';
        }
      } else {
        return 'Username and/or password cannot be empty';
      }
    }
  }

  // loges in the manager
  public function login()
  {
    if (isset($_POST['login'])) {
      $username = isset($_POST['username']) ? htmlspecialchars(trim($_POST['username'])) : '';
      $password = isset($_POST['password']) ? htmlspecialchars(trim($_POST['password'])) : '';
      if (!empty($username) && !empty($password)) {
        $loginSql = "SELECT `password` FROM `manager` WHERE `username` = ?";
        $login = $this->mysqli->prepare($loginSql);
        $login->bind_param('s', $username);
        $login->execute();
        $login->store_result();
        $totalRows = $login->num_rows;
        if ($totalRows > 0) {
          $login->bind_result($hashPassword);
          $login->fetch();
          $login->close();
          if (password_verify($password, $hashPassword)) {
            self::logInSession();
            header("Location: manage");
            return 'Login successfull';
          } else {
            return 'Invalid password';
          }
        } else {
          $login->close();
          return 'Invalid username';
        }
      } else {
        return 'Username and/or password cannot be empty';
      }
    }
  }

  // creates a new HTML table with data prefilled to be showed for the manager
  public function data()
  {
    $rows = ['EOInumber', 'reference', 'firstname', 'lastname', 'dob', 'gender', 'address', 'suburb', 'state', 'postcode', 'email', 'phone', 'skills', 'otherskills', 'status'];
    $dataSql = "SELECT `EOInumber`, `reference`, `firstname`, `lastname`, `dob`, `gender`, `address`, `suburb`, `state`, `postcode`, `email`, `phone`, `skills`, `otherskills`, `status` FROM `application`";
    $data = $this->mysqli->query($dataSql);
    $totalRows = $data->num_rows;
    $table = '<table id="manage-table" class="table tablesorter table-hover table-bordered manage-table"><thead><tr><th>EOInumber</th><th>reference</th><th>firstname</th><th>lastname</th><th>dob</th><th>gender</th><th>address</th><th>suburb</th><th>state</th><th>postcode</th><th>email</th><th>phone</th><th>skills</td><th>otherskills</th><th>status</th><th>Edit</th></tr></thead><tbody>';
    if ($totalRows > 0) {
      while($row = $data->fetch_assoc()) {
        $table .= '<tr>';
        foreach ($rows as $value) {
          $table .= '<td>'.$row[$value].'</td>';
        }
        $table .= '<td><a href="editApplication?eoi='.$row['EOInumber'].'"><img src="assets/img/edit.png" alt="edit" class="edit" /></a></td>';
        $table .= '</tr>';
      }
    }
    $table .= '</tbody></table>';
    return $table;
  }

  public function sortDropdown()
  {
    return '<form method="GET" action="sort">
    <select name="sort">
      <option value="EOInumber">EOI number</option>
      <option value="reference">reference</option>
      <option value="firstname">first name</option>
      <option value="lastname">Date of birth</option>
      <option value="gender">gender</option>
      <option value="address">address</option>
      <option value="suburb">suburb</option>
      <option value="state">state</option>
      <option value="postcode">postcode</option>
      <option value="email">email</option>
      <option value="phone">phone</option>
      <option value="skills">skills</option>
      <option value="otherskills">otherskills</option>
      <option value="status">status</option>
    </select>
    <select name="by">
      <option value="ASC">Ascending</option>
      <option value="DESC">Descending</option>
    </select>
    <button type="submit" name="sortBtn">Sort</button>
    </form>';
  }

  public function dataSort($sort, $by)
  {
    $rows = ['EOInumber', 'reference', 'firstname', 'lastname', 'dob', 'gender', 'address', 'suburb', 'state', 'postcode', 'email', 'phone', 'skills', 'otherskills', 'status'];
    if (!in_array($sort, $rows)) {
      $rows = 'EOInumber';
    }
    if ($by !== 'ASC' && $by !== 'DESC') {
      $by = 'ASC';
    }
    // not sanitized for mysql injection
    $dataSql = "SELECT `EOInumber`, `reference`, `firstname`, `lastname`, `dob`, `gender`, `address`, `suburb`, `state`, `postcode`, `email`, `phone`, `skills`, `otherskills`, `status` FROM `application` ORDER BY $sort $by";
    $data = $this->mysqli->query($dataSql);
    $totalRows = $data->num_rows;
    $table = '<table id="manage-table" class="table tablesorter table-hover table-bordered manage-table"><thead><tr><th>EOInumber</th><th>reference</th><th>firstname</th><th>lastname</th><th>dob</th><th>gender</th><th>address</th><th>suburb</th><th>state</th><th>postcode</th><th>email</th><th>phone</th><th>skills</td><th>otherskills</th><th>status</th><th>Edit</th></tr></thead><tbody>';
    if ($totalRows > 0) {
      while($row = $data->fetch_assoc()) {
        $table .= '<tr>';
        foreach ($rows as $value) {
          $table .= '<td>'.$row[$value].'</td>';
        }
        $table .= '<td><a href="editApplication?eoi='.$row['EOInumber'].'"><img src="assets/img/edit.png" alt="edit" class="edit" /></a></td>';
        $table .= '</tr>';
      }
    }
    $table .= '</tbody></table>';
    return $table;
  }

  public function editApplicationForm($eoi)
  {
    $rows = ['reference', 'firstname', 'lastname', 'dob', 'address', 'suburb', 'postcode', 'email', 'phone', 'otherskills', 'status'];
    $eoi = strip_tags(stripslashes(htmlspecialchars(trim($eoi))));
		$sql = "SELECT `reference`, `firstname`, `lastname`, `dob`, `gender`, `address`, `suburb`, `state`, `postcode`, `email`, `phone`, `skills`, `otherskills`, `status` from `application` WHERE `EOInumber` = ?";
		$SearchUser = $this->mysqli->prepare($sql);
		$SearchUser->bind_param('i', $eoi);
    $SearchUser->execute();
    $SearchUser->store_result();
    $totalRows = $SearchUser->num_rows;
    $form = '<form method="POST" action="editApplication?eoi='.$eoi.'">';
    if ($totalRows > 0) {
      $arr = [];
      $SearchUser->bind_result($arr['reference'], $arr['firstname'], $arr['lastname'], $arr['dob'], $arr['gender'], $arr['address'], $arr['suburb'], $arr['state'], $arr['postcode'], $arr['email'], $arr['phone'], $arr['skills'], $arr['otherskills'], $arr['status']);
      $SearchUser->fetch();
      foreach ($rows as $value) {
        $form .= '<div class="form-group">';
        $form .= '<label for="edit-'.$value.'">'.$value.'</label>';
        $form .= '<input type="text" name="'.$value.'" class="form-control" value="'.$arr[$value].'" id="edit-'.$value.'">';
        $form .= '</div>';
      }
      $form .= '<div><fieldset>
        <legend><label class="form-label">Gender</label></legend>
        <div>
          <label for="gender-m">Male</label>
          <input type="radio" name="gender" id="gender-m" value="Male" required '.($arr['gender'] === "Male" ? 'checked' : '').' />
          
          <label for="gender-f">Female</label>
          <input type="radio" name="gender" id="gender-f" value="Female" required '.($arr['gender'] === "Female" ? 'checked' : '').' />
        </div>
      </fieldset></div>';
      $form .= '<div>
      <label for="state" class="form-label">State</label>
      <select name="state" id="state" class="form-input" required>
        <option value="">Select State</option>
        <option value="VIC" '.($arr['state'] === 'VIC' ? 'selected' : '').'>VIC</option>
        <option value="NSW" '.($arr['state'] === 'NSW' ? 'selected' : '').'>NSW</option>
        <option value="QLD" '.($arr['state'] === 'QLD' ? 'selected' : '').'>QLD</option>
        <option value="NT" '.($arr['state'] === 'NT' ? 'selected' : '').'>NT</option>
        <option value="WA" '.($arr['state'] === 'WA' ? 'selected' : '').'>WA</option>
        <option value="SA" '.($arr['state'] === 'SA' ? 'selected' : '').'>SA</option>
        <option value="TAS" '.($arr['state'] === 'TAS' ? 'selected' : '').'>TAS</option>
        <option value="ACT" '.($arr['state'] === 'ACT' ? 'selected' : '').'>ACT</option>
      </select>
    </div>';
      $skillsList = json_decode($arr['skills']);
      $form .= '<div>
      <fieldset>
        <legend><label class="form-label">Skills</label></legend>
        <div>
          <p>
            <input '.(in_array('verbal-skill', $skillsList) ? 'checked' : '').' type="checkbox" name="skill-list[]" value="verbal-skill" id="verbal-skill" />
            <label for="verbal-skill">Excellent verbal and written communication skills</label>
          </p>
          <p>
            <input '.(in_array('computer-skill', $skillsList) ? 'checked' : '').' type="checkbox" name="skill-list[]" value="computer-skill" id="computer-skill" />
            <label for="computer-skill">Strong computer skills, especially the MS Office suite</label>
          </p>
          <p>
            <input '.(in_array('energy-skill', $skillsList) ? 'checked' : '').' type="checkbox" name="skill-list[]" value="energy-skill" id="energy-skill" />
            <label for="energy-skill">A proactive self-starter, with lots of energy </label>
          </p>
          <p>
            <input '.(in_array('standards-skill', $skillsList) ? 'checked' : '').' type="checkbox" name="skill-list[]" value="standards-skill" id="standards-skill" />
            <label for="standards-skill">Ambition to succeed and high standards</label>
          </p>
          <p>
            <input '.(in_array('other', $skillsList) ? 'checked' : '').' type="checkbox" name="skill-list[]" value="other" id="other" />
            <label for="other">Other skills?</label>
          </p>
          <div>
            <p><label for="other-skills" class="form-label">Other skills</label></p>
            <textarea name="other-skills" id="other-skills" class="other-skills" rows="8">'.$arr['otherskills'].'</textarea>
          </div>
        </div>
      </fieldset>
    </div>';
    }
    $form .= '<button type="submit" name="editApplication" class="btn btn-primary">Edit application</button>';
    $form .= '</form>';
    return $form;
  }

  public function searchName($name)
  {
    $rows = ['EOInumber', 'reference', 'firstname', 'lastname', 'dob', 'gender', 'address', 'suburb', 'state', 'postcode', 'email', 'phone', 'skills', 'otherskills', 'status'];
    $name = '%'.strip_tags(stripslashes(htmlspecialchars(trim($name)))).'%';
		$sql = "SELECT `EOInumber`, `reference`, `firstname`, `lastname`, `dob`, `gender`, `address`, `suburb`, `state`, `postcode`, `email`, `phone`, `skills`, `otherskills`, `status` from `application` WHERE `firstname` LIKE ? OR `lastname` LIKE ?";
		$SearchUser = $this->mysqli->prepare($sql);
		$SearchUser->bind_param('ss', $name, $name);
    $SearchUser->execute();
    $SearchUser->store_result();
    $totalRows = $SearchUser->num_rows;
    $table = '<table id="manage-table" class="table tablesorter table-hover table-bordered manage-table"><thead><tr><th>EOInumber</th><th>reference</th><th>firstname</th><th>lastname</th><th>dob</th><th>gender</th><th>address</th><th>suburb</th><th>state</th><th>postcode</th><th>email</th><th>phone</th><th>skills</td><th>otherskills</th><th>status</th><th>Edit</th></tr></thead><tbody>';
    if ($totalRows > 0) {
      $arr = [];
      $SearchUser->bind_result($arr['EOInumber'], $arr['reference'], $arr['firstname'], $arr['lastname'], $arr['dob'], $arr['gender'], $arr['address'], $arr['suburb'], $arr['state'], $arr['postcode'], $arr['email'], $arr['phone'], $arr['skills'], $arr['otherskills'], $arr['status']);
      while($row = $SearchUser->fetch()) {
        $table .= '<tr>';
        foreach ($rows as $value) {
          $table .= '<td>'.$arr[$value].'</td>';
        }
        $table .= '<td><a href="editApplication?eoi='.$row['EOInumber'].'"><img src="assets/img/edit.png" alt="edit" class="edit" /></a></td>';
        $table .= '</tr>';
      }
    }
    $table .= '</tbody></table>';
    return $table;
  }

  public function searchEOI($eoi)
  {
    $rows = ['EOInumber', 'reference', 'firstname', 'lastname', 'dob', 'gender', 'address', 'suburb', 'state', 'postcode', 'email', 'phone', 'skills', 'otherskills', 'status'];
    $eoi = strip_tags(stripslashes(htmlspecialchars(trim($eoi))));
		$sql = "SELECT `EOInumber`, `reference`, `firstname`, `lastname`, `dob`, `gender`, `address`, `suburb`, `state`, `postcode`, `email`, `phone`, `skills`, `otherskills`, `status` from `application` WHERE `EOInumber` = ?";
		$SearchUser = $this->mysqli->prepare($sql);
		$SearchUser->bind_param('i', $eoi);
    $SearchUser->execute();
    $SearchUser->store_result();
    $totalRows = $SearchUser->num_rows;
    $table = '<table id="manage-table" class="table tablesorter table-hover table-bordered manage-table"><thead><tr><th>EOInumber</th><th>reference</th><th>firstname</th><th>lastname</th><th>dob</th><th>gender</th><th>address</th><th>suburb</th><th>state</th><th>postcode</th><th>email</th><th>phone</th><th>skills</td><th>otherskills</th><th>status</th><th>Edit</th></tr></thead><tbody>';
    if ($totalRows > 0) {
      $arr = [];
      $SearchUser->bind_result($arr['EOInumber'], $arr['reference'], $arr['firstname'], $arr['lastname'], $arr['dob'], $arr['gender'], $arr['address'], $arr['suburb'], $arr['state'], $arr['postcode'], $arr['email'], $arr['phone'], $arr['skills'], $arr['otherskills'], $arr['status']);
      while($row = $SearchUser->fetch()) {
        $table .= '<tr>';
        foreach ($rows as $value) {
          $table .= '<td>'.$arr[$value].'</td>';
        }
        $table .= '<td><a href="editApplication?eoi='.$row['EOInumber'].'"><img src="assets/img/edit.png" alt="edit" class="edit" /></a></td>';
        $table .= '</tr>';
      }
    }
    $table .= '</tbody></table>';
    return $table;
  }

  // deleted all data from the database matching deleteRef job reference
  public function delete()
  {
    if (isset($_POST['delete'])) {
      $ref = isset($_POST['deleteRef']) ? htmlspecialchars(trim($_POST['deleteRef'])) : '';
      if (!empty($ref)) {
        $deleteRefSQL = "DELETE FROM `application` WHERE `reference` = ?";
        $delteRef = $this->mysqli->prepare($deleteRefSQL);
        $delteRef->bind_param('s', $ref);
        $result = $delteRef->execute();
        if ($result) {
          $delteRef->close();
          return 'Job reference '.$ref.' successfully deleted';
        } else {
          $delteRef->close();
          return 'Unable to delete job references';
        }
      }  else {
        return 'reference number cannot be empty';
      }
    }
  }

  private function sanitize($data)
  {
    return htmlspecialchars(trim($data));
  }

  // updates application of any row based on the EOINumber
  public function editApplication()
  {
    if (isset($_POST['editApplication']) && isset($_GET['eoi'])) {
      $eoi = htmlspecialchars(trim($_GET['eoi']));
      $this->Reference = $this->sanitize($_POST['reference']);
      $this->FirstName = $this->sanitize($_POST['firstname']);
      $this->LastName = $this->sanitize($_POST['lastname']);
      $this->DOB = $this->sanitize($_POST['dob']);
      $this->Gender = $this->sanitize($_POST['gender']);
      $this->StreetAddress = $this->sanitize($_POST['address']); 
      $this->Suburb = $this->sanitize($_POST['suburb']);
      $this->State = $this->sanitize($_POST['state']);
      $this->Postcode = $_POST['postcode'];
      $this->EmailAddress = $this->sanitize($_POST['email']);
      $this->PhoneNumber = $this->sanitize($_POST['phone']);
      $this->SkillList = json_encode($_POST['skill-list']);
      $this->OtherSkills = isset($_POST['otherskills']) ? $this->sanitize($_POST['otherskills']) : '';
      $this->Status = $this->sanitize($_POST['status']);

      // update record
      $applySql = 'UPDATE `application` SET `reference` = ?, `firstname` = ?, `lastname` = ?, `dob` = ?, `gender` = ?, `address` = ?, `suburb` = ?, `state` = ?, `postcode` = ?, `email` = ?, `phone` = ?, `skills` = ?, `otherskills` = ?, `status` = ? WHERE `EOINumber` = ?';
      $apply = $this->mysqli->prepare($applySql);
      $apply->bind_param('ssssssssisssssi',
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
        $this->Status,
        $eoi
      );
      $apply->execute();
      print "Application has been edited";
      $apply->close();
    }
  }

  public function __destruct()
  {
    parent::__destruct();
  }
}

?>