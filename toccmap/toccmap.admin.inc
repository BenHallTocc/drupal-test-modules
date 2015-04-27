<?php

/**
 * Implements hook_form()
 * 
 * @return array
 */
function toccmap_config_form()
{
    $form['config'] = array(
        '#type' => 'fieldset',
        '#title' => t('TOCC Map config')
    );
    
    $form['config']['toccmap_base_image'] = array(
        '#type' => 'file',
        '#title' => t('Map Base Image'),
        '#description' => 'The main map image to be used as a base.'
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
function toccmap_config_form_submit($form, $form_state)
{
    tabs_api_form_save($form, $form_state, 'toccmap');
}
