var assert = require('assert');
var solution085 = require('../src/euler/solution085');

describe('Solution085', function() {
  describe('answer', function() {
    it('will answer problem 085', function() {
      assert.equal(solution085.answer(), 2772);
    });
  });
});