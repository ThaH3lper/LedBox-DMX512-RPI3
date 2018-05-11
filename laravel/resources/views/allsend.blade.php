
<!DOCTYPE html>
<html>
    <head>
        <title>Laravel</title>

        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
        <meta name="viewport" content="width=device-width, initial-scale=1">

    </head>
    <body>
        <div class="container">
            <div class="row">
              <div class="col-lg-12">
                    <form action="{{ action('SendController@allsend') }}" method="get">
                        <div id="cp2" class="input-group colorpicker colorpicker-component"> 
                            <input name="color" class="jscolor jscolor-active" type="text" value="{{$name}}">
                        </div>
                        <script src="{{ URL::asset('assets/scripts/jscolor.js') }}"></script>
                        <input class="btn btn-lg btn-success" style="width:100%;" type="submit" value="Send">
                    </form>
                    <br>
                    <form action="{{ action('SendController@welcome') }}" method="get">
                        <input class="btn btn-lg btn-info" type="submit" value="Back">
                    </form>
              </div>
            </div>
        </div>
    </body>
</html>
