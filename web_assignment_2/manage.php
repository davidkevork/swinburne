<?php
  session_start();
  include './Classes/capture.php';
  require './Classes/Manage.class.php';
  capture();
  $Manage = new Manage;
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Manage</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="assets/css/normalize.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="assets/css/style.css" />
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
    <script src="assets/js/jquery-3.3.1.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
    <script src="assets/js/jquery.tablesorter.pager.js"></script>
  </head>
  <body>
    <header id="header">
      <div class="header-center z-depth-2 center">
        <div class="header-left">
          <a href="/" class="logo"></a>
          <nav>
            <a href="index" class="header-link">Index</a>
          </nav>
        </div>
        <div class="header-right">
          <a href="logout" class="header-link">Logout</a>
        </div>
      </div>
    </header>
    <div class="container">
      <?php
        if (!$Manage->isLoggedInSession()) {
          ?>
            <p class="lead text-center">Please <a href="loginManager">login</a> to continue</p>
          <?php
        } else {
          echo $Manage->data();
          echo '<p><a href="delete" target="_blank">Delete Job Reference</a></p>';
        }
      ?>
    </div>
    <script>
      $(document).ready(function() 
        { 
            $("#manage-table").tablesorter({sortList:[[0,0],[2,1]], widgets: ['zebra']}); 
        } 
      );
  </script>
  </body>
</html>