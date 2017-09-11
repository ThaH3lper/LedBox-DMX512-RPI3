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
              {{$name}}
                    <form action="{{ action('SendController@testview') }}" method="get">
                        <div id="cp2" class="input-group colorpicker colorpicker-component"> 
                            <input name="color" class="jscolor jscolor-active" type="text" value="{{$name}}">
                        </div>
                        <script src="http://jscolor.com/release/2.0/jscolor-2.0.4/jscolor.js"></script>
                        <input class="btn btn-lg btn-success" style="width:100%;" type="submit" value="Send">
                    </form>
              </div>
            </div>
        </div>
    </body>
</html>
