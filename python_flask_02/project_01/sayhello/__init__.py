from flask import Flask
from flask_bootstrap import Bootstrap
from flask_moment import Moment
from flask_sqlalchemy import SQLAlchemy

app = Flask('sayhello')
app.config.from_pyfile('setting.py')

app.jinja_env.trim_blocks = True
app.jinja_env.lstrip_blocks = True

bootstrap = Bootstrap(app)
moment = Moment(app)
db = SQLAlchemy(app)
#app = Flask('sayhello',template_folder='templates')
print("你好")
from sayhello import views


