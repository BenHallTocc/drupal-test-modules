<?php

/**
 * Implements hook_form()
 * 
 * @return array
 */
function toccquoteoftheday_config_form()
{
    $form['config'] = array(
        '#type' => 'fieldset',
        '#title' => t('TOCC Quote of the Day config')
    );
    
    /*$form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save')
    );*/
    
    return system_settings_form($form);  // Not interacting with API!
}

/**
 * Implements hook_form_submit()
 */
/*function toccquoteoftheday_config_form_submit($form, $form_state)
{
    tabs_api_form_save($form, $form_state, 'toccquoteoftheday');
}*/
