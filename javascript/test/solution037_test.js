var assert = require('assert');
var solution037 = require('../src/euler/solution037');

describe('Solution037', function() {
  describe('answer', function() {
    it('will answer problem 037', function() {
      assert.equal(solution037.answer(), 748317);
    });
  });
});