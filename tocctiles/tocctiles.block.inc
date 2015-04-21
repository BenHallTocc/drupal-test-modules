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
        'cache' => DRUPAL_CACHE_PER_ROLE
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
            $block['subject'] = t('TOCC Tiles');
            $block['content']['#markup'] = theme(
                    $delta,
                    array(
                        'content' => 'tocctiles_block',
                        'tiles' => tocctiles_get_tiles()
                    )
            );
            
            break;
    }
    
    switch($delta) {
        case 'tocctiles_block':
            $path = drupal_get_path('module', 'tocctiles');
            
            $block['content']['#attached'] = array();
            $block['content']['#attached']['css'] = array(
                $path . '/css/tocctiles.block.css'
            );
            $block['content']['#attached']['js'][] = $path . '/js/tocc.tiles.js';
            
            break;            
    }
    
    return $block;
}

/**
 * Return the tiles taxonomy
 * 
 * @return array
 */
function tocctiles_get_tiles()
{
    
}
