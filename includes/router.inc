<?php
require_once CONCRETE_ROOT . '/includes/controller.inc';

function concrete_route() {
  global $conf;
  
  $routings = isset($conf['routings']) ? $conf['routings'] : array();
  foreach ($routings as $key => $class) {
    if (preg_match($key, $_GET['q'])) {
      include_once './controllers/' . $class . '.inc';
      return new $class();
    }
  }
  require_once CONCRETE_ROOT . '/controllers/NotFoundController.inc';
  return new NotFoundController();
}
