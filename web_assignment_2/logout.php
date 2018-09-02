<?php

  // destroys the session of the user (logout)
  session_start();
  session_destroy();
  header("Location: index");

?>