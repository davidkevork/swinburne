<?php

if ($_SERVER['HTTP_REFERER'] == null) {
  header('Location: apply');
  die();
}

require_once './Classes/Apply.class.php';
require_once './Classes/Table.class.php';

$Apply = new Apply;
$Table = new Table;

$Table->tableExists();
$Apply->apply();

?>
<p><a href="apply">Go Back</a></p>