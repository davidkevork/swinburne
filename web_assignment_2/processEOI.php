<?php

require_once './Classes/Apply.class.php';

$Apply = new Apply;

$Apply->tableExists();
$Apply->apply();

?>
<p><a href="apply">Go Back</a></p>