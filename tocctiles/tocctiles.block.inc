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
            $tiles = tabs_api_get_vocabulary('tocctiles');
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
    /*
    switch($delta) {
        case 'tocctiles_block':
            $path = drupal_get_path('module', 'tocctiles');
            
            $block['content']['#attached'] = array();
            $block['content']['#attached']['css'] = array(
                $path . '/css/tocctiles.block.css'
            );
            //$block['content']['#attached']['js'][] = $path . '/js/tocc.tiles.js';
            
            break;            
    }*/
    
    return $block;
}

/**
 * Return the tiles taxonomy
 * 
 * @return array
 */
/*function tocctiles_get_tiles()
{
    // Function needs completion so that it returns tiles....
}*/

//--------------- Helper Methods ---------------//

/**
 * Returns a test image
 */
function get_test_image_1()
{
    return array(
        'path' => drupal_get_path('module', 'tocctiles') . '/test/test-img-1.jpg',
        'alt' => 'test image 1',
        'width' => '360',
        'height' => '250',
        'attributes' => array(
            'class' => 'test-image',
            'id' => 'test_image_1'
        )
    );
}

/**
 * Returns a test image
 */
function get_test_image_2()
{
    return array(
        'path' => drupal_get_path('module', 'tocctiles') . '/test/test-img-2.jpg',
        'alt' => 'test image 2',
        'width' => '360',
        'height' => '250',
        'attributes' => array(
            'class' => 'test-image',
            'id' => 'test_image_2'
        )
    );
}

function get_test_tile_1()
{
    return array(
        'image' => get_test_image_1(),
        'title' => 'Luxury Properties',
        'description' => 'We have many 5 Star properties available! ' .
                         'Dont hesitate! See what we have to offer today ' .
                         'by clicking on the image.',
        'buttontext' => 'Discover More',
        'link' => 'http://originalcottages.co.uk/'
    );
}
