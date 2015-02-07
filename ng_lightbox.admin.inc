<?php

/**
 * @file
 * Admin settings for NG Lightbox.
 */

/**
 * Form callback.
 */
function ng_lightbox_settings() {
  $form['container']['ng_lightbox_patterns'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('ng_lightbox_patterns', ''),
    '#description' => t('New line separated paths'),
  );
  $form['container']['ng_lightbox_skip_admin_paths'] = array(
    '#title' => t('Skip all admin paths'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('ng_lightbox_skip_admin_paths', TRUE),
    '#description' => t('This will exclude all admin paths from the lightbox. If you want some paths, see hook_ng_lightbox_ajax_path_alter().'),
  );

  return system_settings_form($form);
}
