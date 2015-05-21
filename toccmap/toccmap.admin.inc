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
    
    $form['config']['toccmap_default_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Default Panel Title'),
        '#description' => t('Text used for the title of the panel before an area is selected'),
        '#default_value' => variable_get('toccmap_default_title', '')
    );
    
    $form['config']['toccmap_default_desc'] = array(
        '#type' => 'textarea',
        '#title' => t('Default Panel Description'),
        '#description' => t('Text used for the body of the panel before an area is selected'),
        '#default_value' => variable_get('toccmap_default_desc', '')
    );
    
    $form['config']['toccmap_base_image'] = array(
        '#type' => 'managed_file',
        '#title' => t('Map Base Image'),
        '#description' => 'The main map image to be used as a base.',
        '#default_value' => variable_get('toccmap_base_image', NULL),
        '#upload_location' => 'public://'
    );
    
    $form['config']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
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
