<?php

class COMMON {
  public function header() {
    echo '<header id="header">
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
    <a href="enhancements" class="header-link">Enhancements</a>
    <a href="enhancements2" class="header-link">Enhancements 2</a>
  </div>
</div>
</header>';
  }

  public function headerManage() {
  echo '<header id="header">
<div class="header-center z-depth-2 center">
  <div class="header-left">
    <a href="/" class="logo"></a>
    <nav>
      <a href="manage" class="header-link">Manage</a>
    </nav>
  </div>
  <div class="header-right">
    <a href="logout" class="header-link">Logout</a>
  </div>
</div>
</header>';
  }

  public function footer() {
  echo '<footer>
<div class="footer-links">
  &copy; 2018 <a href="mailto:102100902@swin.edu.au">102100902@swin.edu.au</a>
</div>
</footer>';
  }
}

?>