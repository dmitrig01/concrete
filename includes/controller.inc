<?php

abstract class Controller {
  public $bootstrap_phase = DRUPAL_BOOTSTRAP_FULL;
  function route($uri) {
    drupal_bootstrap($this->bootstrap_phase);
    _system_rebuild_theme_data();
    list_themes(TRUE);
    $this->page($uri);
  }
  abstract function page($uri);
}

abstract class DrupalController extends Controller {
  public $delivery_callback;
  function route($uri) {
    $output = parent::route($uri);
    menu_get_item($uri);
    drupal_deliver_page($output, $this->delivery_callback);
  }
}
