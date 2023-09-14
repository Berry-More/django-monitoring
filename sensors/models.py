from django.db import models

# Create your models here.
class Sensor(models.Model):
    name = models.CharField(max_length=10)
    location = models.CharField(max_length=20)
    num_of_records = models.IntegerField(default=0)

    def __str__(self):
        return self.name
