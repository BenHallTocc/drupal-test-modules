<?php

/**
 * Implements hook_block_info()
 * 
 * @return array
 */
function tocctiles_block_info()
{
    $blocks['tocctiles_block'] = array(
        'info' => t('TOCC Tiles'),
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
function tocctiles_block_view($delta = '')
{
    $block = array();
    $title = '';
    
    switch($delta) {
        case 'tocctiles_block':
            $title = db_query(
                    "SELECT title FROM {block} where delta='" . $delta . "' and `status`=1"
            )->fetchField();
            break;
    }
        
    switch($delta) {
        case 'tocctiles_block':
            $tiles = _tocctiles_get_tiles();
            $tiles_themed = array();
            
            foreach ($tiles as $taxid => $field) {               
                $name = $field->name->value();
                $image = $field->tocctiles_image->value();
                $description = $field->tocctiles_description->value();
                $buttontext = $field->tocctiles_buttontext->value();
                $link = $field->tocctiles_link->value();
                
                $tiles_themed[] = theme(
                    'tocctile',
                    array(
                        'name' => $name,
                        'image' => theme(
                                'image',
                                array_merge(
                                    $image,
                                    array(
                                        'path' => file_create_url($image['uri'])
                                    )
                                )
                        ),
                        'description' => $description,
                        'buttontext' => $buttontext,
                        'link' => $link
                    )
                );
            }
            
            $block['subject'] = t('TOCC Tiles: Block');
            $block['content']['#markup'] = theme(
                $delta,
                array(
                    'title' => $title,
                    'tiles' => $tiles_themed
                )
            );
            
            break;
    }
    
    return $block;
}

//--------------- Helper Methods ---------------//

/**
 * Return the tiles taxonomy
 * 
 * @return array
 */
function _tocctiles_get_tiles()
{
    $tiles = tabs_api_get_vocabulary('tocctiles');
    
    return array_filter($tiles, function($ele) {
        return $ele->tocctiles_visible->value() == 1;
    });
}

