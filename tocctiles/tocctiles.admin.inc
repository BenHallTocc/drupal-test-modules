<?php

/**
 * Implements hook_form()
 * 
 * @return array
 */
function tocctiles_config_form()
{
    $form['config'] = array(
        '#type' => 'fieldset',
        '#title' => t('TOCC Tiles config')
    );
    
    $form['config']['tocctiles_num_tiles'] = array(
        '#type' => 'select',
        '#title' => t('Number of Tiles'),
        '#description' => 'The number of tiles displayed in the block',
        '#default_value' => variable_get('tocctiles_num_tiles', '2'),
        '#options' => array(
            '2' => t('2'),
            '4' => t('4'),
            '6' => t('6'),
            '8' => t('8')
        )
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
/*function tocctiles_config_form_submit($form, $form_state)
{
    tabs_api_form_save($form, $form_state, 'tocctiles');
}*/
