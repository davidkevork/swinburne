<?php
  session_start();
  include './Classes/capture.php';
  require './Classes/Manage.class.php';
  include './common.php';
  require_once './Classes/Table.class.php';
  capture();
  $Table = new Table;
  $Manage = new Manage;
  $Table->tableExists();
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
    <?php COMMON::headerManage(); ?>
    <div class="container">
      <?php
        if (!$Manage->isLoggedInSession()) {
          ?>
            <p class="lead text-center">Please <a href="loginManager">login</a> to continue</p>
          <?php
        } else {
          echo $Manage->data();
          echo '<p><a href="delete">Delete Job Reference</a></p>';
          echo '<p><a href="searchName">Search by Name</a></p>';
          echo '<p><a href="searchEOI">Search by EOI number</a></p>';
          echo $Manage->sortDropdown();
        }
      ?>
    </div>
    <?php COMMON::footer(); ?>
    <script>
      $(document).ready(function() 
        { 
            $("#manage-table").tablesorter({sortList:[], widgets: ['zebra']}); 
        } 
      );
  </script>
  </body>
</html>