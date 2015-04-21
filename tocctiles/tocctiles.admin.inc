<?php

/**
 * Implements hook_form()
 */
function tocctiles_config_form()
{
    $form['config'] = array(
        '#type' => 'fieldset',
        '#title' => t('TOCC Tiles config')
    );
    
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save')
    );
    
    return $form;
}

/**
 * Implements hook_form_submit()
 */
function tocctiles_config_form_submit($form, $form_state)
{
    tabs_api_form_save($form, $form_state, 'tocctiles');
}
