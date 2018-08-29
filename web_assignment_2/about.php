<?php
  include './Classes/capture.php';
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
  <header id="header">
    <div class="header-center z-depth-2 center">
      <div class="header-left">
        <a href="/" class="logo"></a>
        <nav>
          <a href="index" class="header-link">Home</a>
          <a href="jobs" class="header-link">Jobs</a>
          <a href="apply" class="header-link">Apply</a>
          <a href="about" class="header-link active">About</a>
        </nav>
      </div>
      <div class="header-right">
        <a href="manage" class="header-link">Manage</a>
        <a href="enhancements" class="header-link">Enhancements</a>
        <a href="enhancements2" class="header-link active">Enhancements 2</a>
      </div>
    </div>
  </header>
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
  <footer>
    <div class="footer-links">
      &copy; 2018 <a href="mailto:102100902@swin.edu.au">102100902@swin.edu.au</a>
    </div>
  </footer>
</body>
</html>