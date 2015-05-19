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
            $areas_menu = array();
            $areas_info_themed = array();
            $map_areas_themed = array();
            
            foreach ($areas as $taxid => $field) {               
                $name = $field->name->value();
                $hoverimage = $field->area_hoverimage->value();
                $description = $field->area_description->value();
                $linktitle = $field->area_linktitle->value();
                $link = $field->area_link->value();
                $coordinates = $field->area_coordinates->value();
                
                $areas_menu[] = $name;
                
                $areas_info_themed[] = theme(
                    'toccmap_area_info',
                    array(
                        'name' => $name,
                        'description' => $description,
                        'linktitle' => $linktitle,
                        'link' => $link,
                    )
                );
                
                $map_areas_themed[] = theme(
                    'toccmap_map_area',
                    array(
                        'hoverimage' => file_create_url($hoverimage['uri']),                                  
                        'link' => $link,
                        'coordinates' => $coordinates
                    )
                );
            }
            
            $block['subject'] = t('TOCC Map');
            $block['content']['#markup'] = theme(
                $delta,
                array(
                    'area_menu' => $areas_menu,
                    'areas_info' => $areas_info_themed,
                    'map_areas' => $map_areas_themed
                )
            );
            
            break;
    }
    
    return $block;
}
