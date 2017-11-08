var $red;
var $green;
var $blue;
var $top;
var $display;

function rgb2hex(red, green, blue) {
      var rgb = blue | (green << 8) | (red << 16);
      return (0x1000000 + rgb).toString(16).slice(1)
}

function update() {
  //var $top = $(this).find('.top');
  var test = rgb2hex($red, $green, $blue);
  $top.css({'background-color': '#' + test});
  $display.val(test);
}

$( function() {
  console.log("update");
  var $redslider = $(this).find('#redslider');
  var $greenslider = $(this).find('#greenslider');
  var $blueslider = $(this).find('#blueslider');
  $top = $(this).find('.top');
  $display = $(this).find('#colordisplay');
  $redslider.slider({
    range: "min",
    animate: false,
    orientation: "vertical", 
    value: 1,
    min: 0,
    max: 255,
    step: 1,
    slide: function(event, ui) {
      $red = ui.value;
      update();
    },
  });

  $greenslider.slider({
    range: "min",
    animate: false,
    orientation: "vertical", 
    value: 1,
    min: 0,
    max: 255,
    step: 1,
    slide: function(event, ui) {
      $green = ui.value;
      update();
    },
  });

  $blueslider.slider({
    range: "min",
    animate: false,
    orientation: "vertical", 
    value: 1,
    min: 0,
    max: 255,
    step: 1,
    slide: function(event, ui) {
      $blue = ui.value;
      update();
    },
  });
})