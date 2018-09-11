<?php
  include './Classes/capture.php';
  include './common.php';
  capture();
?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <title>Ceylon Textile Suppliers</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" type="text/css" media="screen" href="assets/css/normalize.css" />
  <link rel="stylesheet" type="text/css" media="screen" href="assets/css/style.css" />
</head>
<body id="about">
  <?php COMMON::header(); ?>
  <div class="container center about">
    <div>
      <dl>
        <dt>Name</dt>
        <dd>David</dd>

        <dt>Student Number</dt>
        <dd>102100902</dd>

        <dt>Tutor name</dt>
        <dd>Dr. Grace Tao</dd>

        <dt>Course</dt>
        <dd>COS10020</dd>
        
        <dt>Email</dt>
        <dd><a href="mailto:102100902@swin.edu.au">102100902@swin.edu.au</a></dd>

        <dt>Photo</dt>
        <dd>
          <figure>
            <img src="./assets/img/photo.png" alt="picture of me">
          </figure>
        </dd>
      </dl>
    </div>
    <div>
      <table class="timetable">
        <thead>
          <tr>
            <th>Time</th>
            <th>Monday</th>
            <th>Tuesday</th>
            <th>Wednesday</th>
            <th>Thursday</th>
            <th>Friday</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td>8:30AM - 10:30AM</td>
            <td>COS10007</td>
            <td>MTH10014</td>
            <td>MTH10014</td>
            <td></td>
            <td></td>
          </tr>
          <tr>
            <td>10:30AM - 12:30PM</td>
            <td>INF20015</td>
            <td>INF20015</td>
            <td></td>
            <td></td>
            <td></td>
          </tr>
          <tr>
            <td>12:30PM - 2:30PM</td>
            <td>COS10020</td>
            <td></td>
            <td></td>
            <td>INF20015</td>
            <td></td>
          </tr>
          <tr>
            <td>2:30PM - 4:30PM</td>
            <td>COS10020</td>
            <td>COS10007</td>
            <td>COS10007</td>
            <td>MTH10014</td>
            <td></td>
          </tr>
          <tr>
            <td>4:30PM - 6:30PM</td>
            <td></td>
            <td>COS10020</td>
            <td></td>
            <td></td>
            <td></td>
          </tr>
        </tbody>
      </table>
    </div>
  </div>
  <?php COMMON::footer(); ?>
</body>
</html>