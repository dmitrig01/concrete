<?php

class NotFoundController extends DrupalController {
  function page($uri) {
    return drupal_not_found();
  }
}

