<?php

/**
 * @file
 * Admin settings for NG Lightbox.
 */

/**
 * Form callback.
 */
function ng_lightbox_settings() {
  $form['#config'] = 'ng_lightbox.settings';
  $form['container']['patterns'] = array(
    '#type' => 'textarea',
    '#default_value' => config_get('ng_lightbox.settings', 'patterns', ''),
    '#description' => t('New line separated paths'),
  );
  $form['#config'] = 'ng_lightbox.settings';
  $form['container']['skip_admin_paths'] = array(
    '#title' => t('Skip all admin paths'),
    '#type' => 'checkbox',
    '#default_value' => config_get('ng_lightbox.settings', 'skip_admin_paths', TRUE),
    '#description' => t('This will exclude all admin pages from the lightbox. If you want some paths, see hook_ng_lightbox_ajax_path_alter().'),
  );
  $form['#config'] = 'ng_lightbox.settings';
  $form['container']['disable_css'] = array(
    '#title' => t('Disable CSS'),
    '#type' => 'checkbox',
    '#default_value' => config_get('ng_lightbox.settings', 'disable_css', FALSE),
    '#description' => t('Disable the default CSS provided by NG Lightbox.'),
  );
  return system_settings_form($form);
}
