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


	$("body").keydown(function(e){
		console.log('keydown '+e.which);
	  	switch(e.which) {
			case 38:
			case 87:
				$("button.joystick.up").addClass("btn-danger");
			    break;
			case 40:
			case 83:
				$("button.joystick.down").addClass("btn-danger");
			    break;
			case 37:
			case 65:
				$("button.joystick.left").addClass("btn-danger");
			    break;
			case 39:
			case 68:
				$("button.joystick.right").addClass("btn-danger");
			    break;
		  }
	});

	$("body").keyup(function(e){
		console.log('keyup '+e.which);
	  	switch(e.which) {
			case 38:
			case 87:
				$("button.joystick.up").removeClass("btn-danger");
			    break;
			case 40:
			case 83:
				$("button.joystick.down").removeClass("btn-danger");
			    break;
			case 37:
			case 65:
				$("button.joystick.left").removeClass("btn-danger");
			    break;
			case 39:
			case 68:
				$("button.joystick.right").removeClass("btn-danger");
			    break;
		  }
	});

	//Se algum botão for clicado
    $('button').on('click', function(){
        $btn = $(this);
        action($btn.data('act'));
    });

    function action(action){
        switch(action) {
            case 'up':
                console.log('up');
				websocket.send('up');
                break;
            case 'down':
                console.log('down');
				websocket.send('down');
                break;
            case 'left':
                console.log('left');
				websocket.send('left');
                break;
            case 'right':
                console.log('right');
				websocket.send('right');
                break;
            default:
                console.log('action');
        }

    }
});

window.onload = function() 
{
	var url = 'ws://' + window.location.host;
	websocket = new WebSocket(url);
	websocket.binaryType = "arraybuffer";
	
	websocket.onopen = function(ev)
	{
		setInterval(keepAlive, 1000);
	};

	function keepAlive()
	{
		websocket.send("k");
	}
};
