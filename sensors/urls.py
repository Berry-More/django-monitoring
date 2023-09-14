from django.urls import path

from . import views

app_name = 'sensors'
urlpatterns = [
    path('', views.index, name='index'),
    path('<int:sensor_id>/', views.info, name='info'),
]