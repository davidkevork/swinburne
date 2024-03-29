<?php
  session_start();
  include './Classes/capture.php';
  require './Classes/Manage.class.php';
  require_once './Classes/Table.class.php';
  capture();
  $Table = new Table;
  $Manage = new Manage;
  $Table->tableExists();
  if ($Manage->isLoggedInSession()) {
    header("Location: manage");
  }
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Register Manage</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="assets/css/normalize.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="assets/css/style.css" />
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
    <script src="assets/js/jquery-3.3.1.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
  </head>
  <body>
    <div class="container">
      <form method="POST" action="registerManager">
        <div class="form-group">
          <label for="InputUsername">Username</label>
          <input type="text" name="username" class="form-control" id="InputUsername" placeholder="Username">
        </div>
        <div class="form-group">
          <label for="InputPassword">Password</label>
          <input type="password" name="password" class="form-control" id="InputPassword" placeholder="Password">
        </div>
        <button type="submit" name="register" class="btn btn-primary">Register</button>
      </form>
      <div>Already registered? <a href="loginManager">Login</a></div>
      <div><p><?php echo $Manage->register(); ?></p></div>
    </div>
  </body>
</html>