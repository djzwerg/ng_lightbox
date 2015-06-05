(function ($) {
  "use strict";
  Drupal.behaviors.ng_lightbox = {
    attach: function (context, settings) {

      var self = this;

      // We don't actually use context which could cause issues?
      $('.lightbox__overlay').once(function() {
        // Close the lightbox.
        $(this).click(function(e) {
          if ($(e.target).is('.lightbox__overlay, .lightbox__header')) {
            self.hide($(this).closest('.lightbox__overlay'));
          }
        });
      });

      // This isn't ideal as technically attachBehaviours could be called with
      // document more than once but i'm not sure how to get around that?
      if (context === document) {
        $(document).keyup(function(e) {
          // I couldn't bare to have a lightbox without a keyboard shortcut to
          // close it.
          if (e.which === 27) {
            self.hide($('.lightbox__overlay'));
          }
        });
      }
    },
    hide: function($overlay) {
      // Remove the lock class on body.
      $('body').removeClass('lock');
      $overlay.addClass('ng-hidden');
    }
  };

  Drupal.behaviors.ng_ajax_link = {
    attach: function (context, settings) {
      var $body = $('body');
      if (!$body.hasClass('ng-lightbox-ready')) {
        $body.addClass('ng-lightbox-ready');
        $body.append('<div id="ng-lightbox"></div>');
      }

      $('.ng-lightbox:not(.ng-lightbox-processed)').addClass('ng-lightbox-processed').each(function () {
        var base = 'ng-lightbox';
        var element_settings = {
          url: settings.basePath + 'ng-lightbox',
          event: 'click',
          wrapper: base,
          method: 'append',
          submit: {
            ng_lightbox_path: $(this).attr('href')
          }
        };

        Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
      });
    }
  };

})(jQuery);
