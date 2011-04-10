<?php

define('DRUPAL_ROOT', getcwd() . '/drupal');
chdir(DRUPAL_ROOT);

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_CONFIGURATION);

define('CONCRETE_ROOT', dirname(__FILE__));
require_once CONCRETE_ROOT . '/includes/router.inc';
$controller = concrete_route();

print $controller->route($_GET['q']);
