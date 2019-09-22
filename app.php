<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);

  include('ktupad/ktupad.php');
  class app extends mod {
  public $local= array(
    's' => 'den1.mysql4.gear.host',
    'u' => 'oledktupad',
    'p' => 'Lg2ExXQk3!J-',
    'n'=> 'oledktupad'
    );
  }

  $app = new app();
  $app -> init();

?>
