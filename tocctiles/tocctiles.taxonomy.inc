<?php

function tocctiles_form_taxonomy_form_term_alter(&$form, &$form_state)
{
    if (is_array($form['#term'])
            && array_key_exists('vocabulary_machine_name', $form['#term'])
            && (
                    $form['#term']['vocabulary_machine_name'] == 'tocctiles'
            )
    ) {
        $form['relations']['#access'] = false;
        $form['description']['#access'] = false;
        $form['redirect']['#access'] = false;
        $form['path']['#access'] = false;
        @$form['metatags']['#access'] = false;
    }
}
