<?php

/**
 * Implements hook_block_info()
 * 
 * @return array
 */
function toccmap_block_info()
{
    $blocks['toccmap_block'] = array(
        'info' => t('TOCC Map'),
    );
    
    return $blocks;
}

/**
 * Implements hook_block_view()
 * 
 * Prepares the contents of the block.
 * 
 * @return array
 */
function toccmap_block_view($delta = '')
{
    $block = array();
    $title = '';
    
    switch($delta) {
        case 'toccmap_block':
            $title = db_query(
                    "SELECT title FROM {block} where delta='" . $delta . "' and `status`=1"
            )->fetchField();
            break;
    }
        
    switch($delta) {
        case 'toccmap_block':
            $areas = tabs_api_get_vocabulary('toccmap');
            
            // 'Area Panels' are the blocks of content displayed for each area
            $area_panels_themed = array();
        
            // Retrieving default info section content (see config screen)
            $default_title = variable_get('toccmap_default_title', '');
            $default_desc = variable_get('toccmap_default_desc', '');
        
            // Theming of default content if appropriate
            if (($default_title && strlen($default_title) > 0)
                    && ($default_desc && strlen($default_desc) > 0)) 
            {
                $area_panels_themed[] = theme(
                    'toccmap_area_panel',
                    array(
                        'title' => $default_title,
                        'desc' => $default_desc,
                    )
                );
            }
        
            // Iterating through returned TOCC Map taxonomy
            foreach ($areas as $taxid => $field) {
                $image = $field->toccmap_areaimage->value();
                $image_themed = theme(
                        'image', 
                        array_merge(
                            $image,
                            array(
                                'path' => file_create_url($image['uri'])
                            )
                        )
                );
            
                $area_panels_themed[] = theme(
                    'toccmap_area_panel',
                    array(
                        'image' => $image_themed,
                        'title' => $field->name->value(),
                        'desc' => $field->toccmap_areadesc->value(),
                        'link' => $field->toccmap_link->value(),
                        'buttontext' => $field->toccmap_buttontext->value()
                    )
                );
            }
        
            $block['subject'] = t('TOCC Map');
            $block['content'] = theme(
                $delta,
                array(
                    'area_panels' => $area_panels_themed
                )
            );
            break;
    }
    
    return $block;
}
