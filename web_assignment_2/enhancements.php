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
<body>
  <header id="header">
    <div class="header-center z-depth-2 center">
      <div class="header-left">
        <a href="/" class="logo"></a>
        <nav>
          <a href="index" class="header-link">Home</a>
          <a href="jobs" class="header-link">Jobs</a>
          <a href="apply" class="header-link">Apply</a>
          <a href="about" class="header-link">About</a>
        </nav>
      </div>
      <div class="header-right">
        <a href="manage" class="header-link">Manage</a>
        <a href="enhancements" class="header-link active">Enhancements</a>
        <a href="enhancements2" class="header-link active">Enhancements 2</a>
      </div>
    </div>
  </header>
  <div class="container enhancements">
    <div class="canvas">
      <canvas id="canvas" width="400" height="200" style="border:1px solid #8a22b9;"></canvas>
    </div>
    <div class="solar-map">
      <img src="assets/img/solar.jpg" usemap="#solar-map" alt="enhancement">
      <map name="solar-map">
        <area target="_blank" alt="Sun" title="Sun" href="https://en.wikipedia.org/wiki/Sun" coords="-1,149,96,356,130,507,135,637,118,761,87,875,-1,1051,-1,424,-1,1049,1,142" shape="poly">
        <area target="_blank" alt="Mercury" title="Mercury" href="https://en.wikipedia.org/wiki/Mercury_(planet)" coords="267,571,14" shape="circle">
        <area target="_blank" alt="Venus" title="Venus" href="https://en.wikipedia.org/wiki/Venus" coords="327,556,20" shape="circle">
        <area target="_blank" alt="Earth" title="Earth" href="https://en.wikipedia.org/wiki/Earth" coords="398,537,26" shape="circle">
        <area target="_blank" alt="Mars" title="Mars" href="https://en.wikipedia.org/wiki/Mars_(Planet)" coords="469,522,19" shape="circle">
        <area target="_blank" alt="Jupiter" title="Jupiter" href="https://en.wikipedia.org/wiki/Jupiter" coords="803,446,110" shape="circle">
        <area target="_blank" alt="Saturn" title="Saturn" href="https://en.wikipedia.org/wiki/Saturn" coords="1124,395,168" shape="circle">
        <area target="_blank" alt="Uranus" title="Uranus" href="https://en.wikipedia.org/wiki/Uranus" coords="1379,318,94" shape="circle">
        <area target="_blank" alt="Neptune" title="Neptune" href="https://en.wikipedia.org/wiki/Neptune" coords="1582,263,69" shape="circle">
      </map>
    </div>
  </div>
  <footer>
    <div class="footer-links">
      &copy; 2018 <a href="mailto:102100902@swin.edu.au">102100902@swin.edu.au</a>
    </div>
  </footer>
  <script type="text/javascript">
    let canvas = document.getElementById('canvas');
    let ctx = canvas.getContext('2d');
    let grd = ctx.createLinearGradient(0, 200, 400, 200);
    grd.addColorStop(0, '#c31432');
    grd.addColorStop(1, '#240b36');
    ctx.fillStyle = grd;
    ctx.fillRect(0, 0, 400, 400);
    ctx.fillStyle = '#ffffff';
    ctx.font = '30px Source Sans Pro';
    ctx.fillText('Welcome to Enhancements', 30, 110);
  </script>
</body>
</html>