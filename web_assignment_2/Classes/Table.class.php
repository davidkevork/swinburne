<?php

require_once 'Mysql.class.php';

class Table extends Mysql
{
  // sql for creating application and manager table
  private $applicationTableSql = "CREATE TABLE `application` (
    `EOInumber` int(10) NOT NULL,
    `reference` varchar(6) NOT NULL,
    `firstname` varchar(25) NOT NULL,
    `lastname` varchar(25) NOT NULL,
    `dob` varchar(9) NOT NULL,
    `gender` varchar(10) NOT NULL,
    `address` varchar(40) NOT NULL,
    `suburb` varchar(40) NOT NULL,
    `state` varchar(3) NOT NULL,
    `postcode` int(4) NOT NULL,
    `email` varchar(256) NOT NULL,
    `phone` varchar(12) NOT NULL,
    `skills` varchar(256) NOT NULL,
    `otherskills` varchar(256) NOT NULL,
    `status` varchar(10) NOT NULL
  ) ENGINE=InnoDB DEFAULT CHARSET=latin1;
  ALTER TABLE `application` ADD PRIMARY KEY (`EOInumber`);
  ALTER TABLE `application` MODIFY `EOInumber` int(10) NOT NULL AUTO_INCREMENT;";

  private $managerTableSql = "CREATE TABLE `manager` (
    `id` int(10) NOT NULL,
    `username` varchar(256) NOT NULL,
    `password` varchar(256) NOT NULL
  ) ENGINE=InnoDB DEFAULT CHARSET=latin1;
  ALTER TABLE `manager` ADD PRIMARY KEY (`id`);
  ALTER TABLE `manager` MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;";

  public function __construct()
  {
    parent::__construct();
  }

  // checks if application and manager table exist. If not then create a new one
  public function tableExists()
  {
    $applicationExistsSql = "DESCRIBE `application`";
    $managerExistsSql = "DESCRIBE `manager`";

    $applicationExists = $this->mysqli->query($applicationExistsSql);
    if (!$applicationExists)
    {
      $applicationCreate = $this->mysqli->multi_query($this->applicationTableSql);
    }

    $managerExists = $this->mysqli->query($managerExistsSql);
    if (!$managerExists)
    {
      $managerCreate = $this->mysqli->multi_query($this->managerTableSql);
    }
  }

  public function __destruct()
  {
    parent::__destruct();
  }
}

?>
