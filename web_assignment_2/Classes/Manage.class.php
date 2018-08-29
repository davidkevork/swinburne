<?php

require_once 'Mysql.class.php';

class Manage extends Mysql
{
  public function __construct()
  {
    parent::__construct();
  }

  public static function isLoggedInSession()
  {
    return isset($_SESSION['loggedIn']) && !empty($_SESSION['loggedIn']);
  }

  public static function logInSession()
  {
    $_SESSION['loggedIn'] = 'loggedIn';
  }

  public function register()
  {
    if (isset($_POST['register'])) {
      $username = isset($_POST['username']) ? htmlspecialchars(trim($_POST['username'])) : '';
      $password = isset($_POST['password']) ? htmlspecialchars(trim($_POST['password'])) : '';
      if (!empty($username) && !empty($password)) {
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
        return 'Username and/or password cannot be empty';
      }
    }
  }

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

  public function data()
  {
    $rows = ['EOInumber', 'reference', 'firstname', 'lastname', 'dob', 'gender', 'address', 'suburb', 'state', 'postcode', 'email', 'phone', 'skills', 'otherskills', 'status'];
    $dataSql = "SELECT `EOInumber`, `reference`, `firstname`, `lastname`, `dob`, `gender`, `address`, `suburb`, `state`, `postcode`, `email`, `phone`, `skills`, `otherskills`, `status` FROM `application`";
    $data = $this->mysqli->query($dataSql);
    $totalRows = $data->num_rows;
    $table = '<table id="manage-table" class="table tablesorter table-hover table-bordered manage-table"><thead><tr><th>EOInumber</th><th>reference</th><th>firstname</th><th>lastname</th><th>dob</th><th>gender</th><th>address</th><th>suburb</th><th>state</th><th>postcode</th><th>email</th><th>phone</th><th>skills</td><th>otherskills</th><th>status</th></tr></thead><tbody>';
    if ($totalRows > 0) {
      while($row = $data->fetch_assoc()) {
        $table .= '<tr>';
        foreach ($rows as $value) {
          $table .= '<td>'.$row[$value].'</td>';
        }
        $table .= '</tr>';
      }
    }
    $table .= '</tbody></table>';
    return $table;
  }

  public function delete()
  {
    if (isset($_POST['delete'])) {
      $ref = isset($_POST['deleteRef']) ? htmlspecialchars(trim($_POST['deleteRef'])) : '';
      if (!empty($ref)) {
        $deleteRefSQL = "UPDATE `application` SET `status` = 'deleted' WHERE `reference` = ?";
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

  public function __destruct()
  {
    parent::__destruct();
  }
}


?>