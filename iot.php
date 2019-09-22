<?php
class mod extends ktupad {
  public $mn='data';
  public $tb='data';
  public $data='{"id":"1","nama":"Satu"}';
  public function read() {
    $tb=$this->tb;
    $id=$this->id;
    $conn=$this->connect();
    $sql = "SELECT * FROM $tb where id='$id'";
    $conn=$this->connect();
    $result = $conn->query($sql);
    $row = $result->fetch_assoc();
    if($row){ echo $row['nama'];}
    $conn->close();
  }

}

?>
