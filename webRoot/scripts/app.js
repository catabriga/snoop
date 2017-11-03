var protocol = 
{
    KEEP_ALIVE  : 1,
    UP_DOWN     : 10,
    UP_UP       : 11,
    DOWN_DOWN   : 12,
    DOWN_UP     : 13,
    LEFT_DOWN   : 14,
    LEFT_UP     : 15,
    RIGHT_DOWN  : 16,
    RIGHT_UP    : 17,
};

$(function() {
    console.log('Document ready');
  
	$('body').keydown(function(e){
		console.log('keydown '+e.which);
	  	switch(e.which) {
			case 38:
			case 87:
                action('UP_DOWN');
				$('button.joystick.up').addClass('btn-danger');
			    break;
			case 40:
			case 83:
                action('DOWN_DOWN');
				$('button.joystick.down').addClass('btn-danger');
			    break;
			case 37:
			case 65:
                action('LEFT_DOWN');
				$('button.joystick.left').addClass('btn-danger');
			    break;
			case 39:
			case 68:
                action('RIGHT_DOWN');
				$('button.joystick.right').addClass('btn-danger');
			    break;
		  }
	});

	$('body').keyup(function(e){
		console.log('keyup '+e.which);
	  	switch(e.which) {
			case 38:
			case 87:
                action('UP_UP');
				$('button.joystick.up').removeClass('btn-danger');
			    break;
			case 40:
			case 83:
                action('DOWN_UP');
				$('button.joystick.down').removeClass('btn-danger');
			    break;
			case 37:
			case 65:
                action('LEFT_UP');
				$('button.joystick.left').removeClass('btn-danger');
			    break;
			case 39:
			case 68:
                action('RIGHT_UP');
				$('button.joystick.right').removeClass('btn-danger');
			    break;
		  }
	});

    $('button').on('click', function(){
        $btn = $(this);
        action($btn.data('act'));
    });

    function action(action)
    {
        if(action in protocol)
        {
            console.log(action + ' ' + protocol[action]);
            sendBinaryData(protocol[action])
        }
    }
});

function sendBinaryData(data)
{
    var dataArray = new Uint8Array(1);
    dataArray[0] = data;
    websocket.send(dataArray);
}

window.onload = function() 
{
	var url = 'ws://' + window.location.host;
	websocket = new WebSocket(url);
	websocket.binaryType = 'arraybuffer';
	
	websocket.onopen = function(ev)
	{
		setInterval(keepAlive, 1000);
	};

	function keepAlive()
	{
		sendBinaryData(protocol['KEEP_ALIVE']);
	}
};
