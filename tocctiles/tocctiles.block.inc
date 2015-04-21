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
    
    switch($delta) {
        case 'tocctiles_block':
            $image = get_test_image_1();  // Test!
            //$tile = get_test_tile_1();
            
            $block['content'] = theme('image', $image);  // Uses Test image!
            
            /*$block['content']['#markup'] = theme(
                    $delta,
                    array(
                        'content' => 'tocctiles_block',
                        //'tiles' => tocctiles_get_tiles()
                    )
            );*/
            
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
