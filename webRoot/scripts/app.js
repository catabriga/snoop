$(function() {
    console.log("Document ready");
    $("body").keypress(function(e){
      switch(e.which) {
        case 119:
            action('up');
            break;
        case 115:
            action('down');
            break;
        case 97:
            action('left');
            break;
        case 100:
            action('right');
            break;
      }
    });
    $('button').on('click', function(){
        $btn = $(this);
        action($btn.data('act'));
    });
    function action(action){
        $("button.joystick").removeClass("btn-danger");
        $("button.joystick." + action).addClass("btn-danger");
        switch(action) {
            case 'up':
                console.log('up');
                break;
            case 'down':
                console.log('down');
                break;
            case 'left':
                console.log('left');
                break;
            case 'right':
                console.log('right');
                break;
            default:
                console.log('action');
        }

    }
});
