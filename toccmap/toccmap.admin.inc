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
        '#title' => t('Default Area Panel Title'),
        '#description' => t('Text used for the title of the area panel ' .
                            'displayed before an area is selected. Leave ' .
                            'blank to disable default area panel.'),
        '#default_value' => variable_get('toccmap_default_title', '')
    );
    
    $form['config']['toccmap_default_desc'] = array(
        '#type' => 'textarea',
        '#title' => t('Default Area Panel Description'),
        '#description' => t('Text used for the body of the area panel ' .
                            'displayed before an area is selected. Leave ' .
                            'blank to disable default area panel.'),
        '#default_value' => variable_get('toccmap_default_desc', '')
    );
    
    $form['config']['toccmap_base_image_fid'] = array(
        toccmap_create_image_control('toccmap_base_image_fid', 'Map Base Image')
    );
    
    $form['config']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save')
    );
    
    return $form;  
}

/**
 * Return a drupal form api image control
 * 
 * @param string $name  Variable name of image
 * @param string $label Label
 * 
 * @return array
 */
function toccmap_create_image_control($name, $label)
{
    $imageSettings = array();
    
    // If there is already an uploaded image display the image here
    $fid = variable_get($name, FALSE);
    
    if ($fid !== FALSE && $image = file_load($fid)) {
        $imageSettings[$name . '_open'] = array(
            '#markup' => sprintf(
                '<div class="clearfix"><p style="float: left; margin-right: 10px;">%s</p>',
                theme(
                    'image_style',
                    array(
                        'style_name' => 'thumbnail',
                        'path' => $image->uri,
                        'getsize' => FALSE
                    )
                )
            )
        );
    }
    
    $imageSettings[$name] = array(
        '#type' => 'managed_file',
        '#title' => $label,
        '#description' => 'The main map image to be used as a base.',
        '#default_value' => variable_get($name, NULL),
        '#upload_location' => 'public://'
    );
    
    if ($fid !== FALSE) {
        $imageSettings[$name . '_close'] = array(
            '#markup' => '</div>'
        );
    }
    
    return $imageSettings;
}

/**
 * Implements hook_form_submit()
 */
function toccmap_config_form_submit(&$form, &$form_state)
{
    // Loop through all of the form state values and save
    foreach ($form_state['values'] as $key => $val) {
        // If key is subfixed with 'fid', treat is as an image
        if (substr($key, -3) == 'fid') {
            // Handle image
            toccmap_save_image($form_state, $key);
        } else {
            variable_set($key, $val);
        }
    }
}

/**
 * Save image function
 * 
 * @global stdClass $user
 * 
 * @param array $form_state
 * @param string $fileName
 */
function toccmap_save_image(&$form_state, $fileName)
{
    global $user;
    $fileValue = toccmap_store_image($form_state, $fileName);
    variable_set($fileName, $fileValue);
}

/**
 * Method used to store an image
 * 
 * @global stdClass $user
 * 
 * @param array $form_state
 * @param string $fileName
 * 
 * @return void
 */
function toccmap_store_image(&$form_state, $fileName)
{
    global $user;
    
    if ($form_state['values'][$fileName] != 0) {
        $file = file_load($form_state['values'][$fileName]);
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);

        // Record that the module (in this example, user module) is using the file. 
        file_usage_add($file, 'toccmap', 'user', $user->uid);       
        $fileName = $file->fid;
    } else if($form_state['values'][$fileName] == 0) {
        // Retrieve the old file's id.
        $fid = variable_get($fileName, FALSE);
        $file = $fid ? file_load($fid) : FALSE;
        
        if ($file) {
            file_usage_delete($file, 'toccmap', 'user', $user->uid);
            file_delete($file);
            $fileName = false;
        }
    } else {
        $fid = variable_get($fileName, FALSE);
        $file = $fid ? file_load($fid) : FALSE;
        
        if ($file) {
            file_delete($file);
            $fileName = false;
        }
    }
    
    return $fileName;
}
