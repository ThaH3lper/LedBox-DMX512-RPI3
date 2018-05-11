
<!DOCTYPE html>
<html>
    <head>
        <title>Laravel</title>

        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
        <link rel="stylesheet" href="{{ URL::asset('assets/scripts/jquery-ui.css') }}">
        <link rel="stylesheet" href="{{ URL::asset('assets/css/main.css') }}">
        <script language="JavaScript" type="text/javascript" src="{{ URL::asset('assets/scripts/jquery-3.2.1.min.js') }}"></script>
        <script language="JavaScript" type="text/javascript" src="{{ URL::asset('assets/scripts/jquery-ui.js') }}"></script>
        <script language="JavaScript" type="text/javascript" src="{{ URL::asset('assets/scripts/slider.js') }}"></script>
        <meta name="viewport" content="width=device-width, initial-scale=1, height=device-height">

    </head>
    <body>
        <div class="container">
            <div class="top">
                <form action="{{ action('SendController@sliderpicker') }}" method="get">
                    <input name="color" id="colordisplay" type="text" value="{{$color_hex}}">
                    <input class="btn btn-lg btn-success" type="submit" value="Ship it">
                </form>
                <form action="{{ action('SendController@welcome') }}" method="get">
                    <input class="btn btn-lg btn-info" type="submit" value="Back">
                </form>
            </div>
            <div class="buttom">
                <div class="slider">
                    <div id="redslider"></div>
                </div>
                <div class="slider">
                    <div id="greenslider"></div>
                </div>
                <div class="slider">
                    <div id="blueslider"></div>
                </div>
            </div>
        </div>
    </body>
</html>
