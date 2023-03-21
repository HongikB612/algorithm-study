def solution(m, n, startX, startY, balls):
    return [
        min((startX - x) ** 2 + (startY - y) ** 2
            for x, y in ((-xBall, yBall), (xBall, -yBall), (2 * m - xBall, yBall), (xBall, 2 * n - yBall))
            if not ((startX == xBall and (y > yBall > startY or y < yBall < startY))
                    or
                    (startY == yBall and (x > xBall > startX or x < xBall < startX)))
            )
        for xBall, yBall in balls
    ]
