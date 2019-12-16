import requests
import os
import cv2.cv2 as cv
import numpy as np
import hashlib
import json
from multiprocessing.pool import ThreadPool

target = 50000
items_per_page = 30

pool = ThreadPool(items_per_page)

def get_and_write_photo(photo_id):
    try:
        raw = requests.get(
            f"https://source.unsplash.com/{photo_id}/400x300", timeout=5
        ).content
        image = cv.imdecode(np.fromstring(raw, np.uint8), cv.IMREAD_COLOR)
        h = hashlib.md5(image.data).hexdigest()
        cv.imwrite(f"images/{h}.png", image)
    except:
        pass


page = int(len(os.listdir("images")) / items_per_page)
while True:
    ids = [
        img["id"]
        for img in json.loads(
            requests.get(
                f"https://unsplash.com/napi/search/photos?query=food&xp=&per_page={items_per_page}&page={page}"
            ).text
        )["results"]
    ]
    results = pool.imap_unordered(get_and_write_photo, ids)
    for result in results:
        pass
    print(len(os.listdir("images")))
    if len(os.listdir("images")) >= target:
        exit()
    print("next page")
    page += 1
