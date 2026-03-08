var assert = require('assert');
var solution017 = require('../src/euler/solution017');

describe('Solution017', function() {
  describe('answer', function() {
    it('will answer problem 017', function() {
      assert.equal(solution017.answer(), 21124);
    });
  });
});