<?php

abstract class Model extends Kernel {
  function __construct($id = NULL) {
    if ($id) {
      $this->load($id);
    }
  }
  abstract function load($id);
  abstract function save();
  abstract function delete();
}
