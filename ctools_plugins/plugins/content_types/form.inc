<?php

$plugin = array(
  'title' => t('Form'),
  'description' => t('Content type form rendering custom text.'),
  'render callback' => 'form_content_type_render',
  'edit form' => 'form_edit_form',
  'category' => t('Anton L. panes'),
  'single' => TRUE,
);

/**
 * 'Form' for the content type plugin.
 */

function form_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];

  $form['text'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter text to render'),
    '#default_value' => !empty($conf['text']) ? $conf['text'] : '',
  );

  return $form;
}

/**
 * Form Submit for the form_edit_form.
 */

function form_edit_form_submit($form, &$form_state) {

  $form_state['config'] = array(
    'text' => $form_state['values']['text'],
  );

  drupal_set_message(t('Submitting Text: @values', array('@values' => var_export($form_state['values'], TRUE))));
}

/**
 * Render callback for the content type.
 */

function form_content_type_render($subtype, $config, $args, $context) {

  if (empty($config['text'])) {
    return;
  }

  $block = new stdClass();
  $block->content = $config['text'];
  return $block;
}
