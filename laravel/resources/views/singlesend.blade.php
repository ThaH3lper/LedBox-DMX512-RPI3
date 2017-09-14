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
                    <form action="{{ action('SendController@singleColorView') }}" method="get">
                        <div id="cp2" class="input-group colorpicker colorpicker-component"> 
                            <input name="color" class="jscolor jscolor-active" type="text" value="{{$color}}">
                        </div>
                        <script src="http://jscolor.com/release/2.0/jscolor-2.0.4/jscolor.js"></script>
                        <input type="radio" name="channel" value="1"> Left of TV<br>
                        <input type="radio" name="channel" value="2"> Center of TV<br>
                        <input type="radio" name="channel" value="3"> Right of TV<br>
                        <input type="radio" name="channel" value="0"> Bass
                        <input class="btn btn-lg btn-success" style="width:100%;" type="submit" value="Send">
                    </form>
                    <br>
                    <p><a class="btn btn-lg btn-info" href="/laravel/public" role="button">Back</a></p>
              </div>
            </div>
        </div>
    </body>
</html>