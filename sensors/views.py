from django.shortcuts import render, get_object_or_404

from .models import Sensor

# Create your views here.
def index(request):
    sensors = Sensor.objects.order_by('-id')[::-1]
    names = []
    data = []
    for i in sensors:
        names.append(i.name)
        data.append(i.num_of_records)
    context = {'sensors': sensors, 'names': names, 'data': data, 'title': 'Main page'}
    return render(request, 'sensors/index.html', context)

def info(request, sensor_id):
    sensor = get_object_or_404(Sensor, pk=sensor_id)
    return render(request, 'sensors/info.html', 
    {'sensor': sensor, 'title': 'Sensor info'})
