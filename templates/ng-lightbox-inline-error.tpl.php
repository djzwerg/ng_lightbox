<?php
/**
 * @file
 * Inline lightbox error messages.
 */

?>

<div class='ng-lightbox-inline-errors'>
  <?php foreach ($messages as $message) : ?>
    <div><?php print $message; ?></div>
  <?php endforeach; ?>
</div>
